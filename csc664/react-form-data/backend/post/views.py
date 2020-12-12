from django.shortcuts import render
from django.shortcuts import get_object_or_404
from .serializers import *
from .models import *
from django.db import IntegrityError
from rest_framework import status
from rest_framework import viewsets
from rest_framework.views import APIView
from rest_framework.parsers import MultiPartParser, FormParser,JSONParser
from rest_framework.response import Response
from rest_framework.decorators import action
from django.db.models import F
# Create your views here.

class ImgFileView(viewsets.ModelViewSet):
    parser_classes = [MultiPartParser, FormParser,JSONParser]
    queryset = ImgFile.objects.all()
    serializer_class = ImgFileSerializer


    @action(methods=['get'], detail=True)
    def regions(self, request, pk=None):
        regions = Region.objects.filter(image=pk)
        serializer = RegionSerializer(regions, many=True, context={'request': request})
        return Response(serializer.data)

    @action(methods=['get'], detail=True)
    def unlinked(self, request, pk=None):
        thisImage = ImgFile.objects.get(pk=pk)
        facet = request.query_params.get('facet')
        print(facet)
        images = ImgFile.objects.filter(region__facets=facet).exclude(id__in=thisImage.linkedImages.all()).distinct()
        images = images.exclude(id=pk)
        serializer = ImgFileSerializer(images, many=True, context={'request': request})
        return Response(serializer.data)

    @action(methods=['get'], detail=True)
    def linked(self, request, pk=None):
        thisImage = ImgFile.objects.get(pk=pk)
        images = thisImage.linkedImages.all()
        serializer = ImgFileSerializer(images, many=True, context={'request': request})
        return Response(serializer.data)

    def make_graph(self, parent, facet):
        temp1 = ImgFile.objects.get(pk=parent)
        print(temp1)
        temp2 = ImgFile.objects.filter(region__facets=facet).filter(id__in=temp1.linkedImages.all()).distinct()
        print(temp2)
        print(facet)
        for image in temp2:
            Link.objects.create(source=temp1, target=image)
            try:
                temp3 = ImgFile.objects.get(pk=image.pk)
                Node.objects.create(pk=image.pk, node=temp3, image=temp3.image)
            except IntegrityError:
                break
            self.make_graph(image.id, facet)

    @action(methods=['get'], detail=True)
    def get_graph(self, request, pk=None):
        Node.objects.all().delete()
        Link.objects.all().delete()
        thisImage = ImgFile.objects.get(pk=pk)
        Node.objects.create(pk=thisImage.id, node=thisImage, image=thisImage.image)
        print(request.query_params.get("facet"))
        self.make_graph(thisImage.id, request.query_params.get("facet"))

        nodes = Node.objects.all()
        links = Link.objects.all()

        node_serializer = NodeSerializer(nodes, many=True, context={'request': request})
        link_serializer = LinkSerializer(links, many=True, context={'request': request})

        return Response({'nodes':node_serializer.data, 'links':link_serializer.data})

    @action(methods=['post'], detail=True)
    def addlink(self, request, pk=None):
        links = request.data.get("linkedImages")
        thisImage = ImgFile.objects.get(pk=pk)

        if(links != None):
            for val in links:
                thisImage.linkedImages.add(val)
            thisImage.save()
            return Response( status=status.HTTP_202_ACCEPTED)
        return Response( status=status.HTTP_400_BAD_REQUEST)

    def get(self, request, *args, **kwargs):
        imgFiles = ImgFile.objects.all()
        serializer = ImgFileSerializer(imgFiles, many=True, context={'request': request})
        return Response(serializer.data)

    def post(self, request, *args, **kwargs):
        imgFile_serializer = ImgFileSerializer(data=request.data)
        if imgFile_serializer.is_valid():
            imgFile_serializer.save()
            return Response(imgFile_serializer.data, status=status.HTTP_201_CREATED)
        else:
            print('error', imgFile_serializer.errors)
            return Response(imgFile_serializer.errors, status=status.HTTP_400_BAD_REQUEST)


class RegionView(viewsets.ModelViewSet):
    parser_classes = (MultiPartParser, FormParser)
    queryset = Region.objects.all()
    serializer_class = RegionSerializer

    def get(self, request, *args, **kwargs):
        regions = Region.objects.all()
        serializer = RegionSerializer(regions, many=True)
        return Response(serializer.data)

    def post(self, request, *args, **kwargs):
        region_serializer = RegionSerializer(data=request.data)
        if region_serializer.is_valid():
            region_serializer.save()
            return Response(region_serializer.data, status=status.HTTP_201_CREATED)
        else:
            print('error', region_serializer.errors)
            return Response(region_serializer.errors, status=status.HTTP_400_BAD_REQUEST)



class FacetView(viewsets.ModelViewSet):
    parser_classes = (MultiPartParser, FormParser)
    queryset = Facet.objects.all()
    serializer_class = FacetSerializer


    @action(methods=['get'], detail=True)
    def images(self, request, pk=None):
        images = ImgFile.objects.filter(region__facets=pk)
        serializer = ImgFileSerializer(images, many=True, context={'request': request})
        return Response(serializer.data)

    def get(self, request, *args, **kwargs):
        facets = Facet.objects.all()
        serializer = FacetSerializer(facets, many=True)
        return Response(serializer.data)

    def post(self, request, *args, **kwargs):
        facet_serializer = FacetSerializer(data=request.data)
        if facet_serializer.is_valid():
            facet_serializer.save()
            return Response(facet_serializer.data, status=status.HTTP_201_CREATED)
        else:
            print('error', facet_serializer.errors)
            return Response(facet_serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class NodeView(viewsets.ModelViewSet):
    parser_classes = (MultiPartParser, FormParser)
    queryset = Node.objects.all()
    serializer_class = NodeSerializer

    def get(self, request, *args, **kwargs):
        nodes = Node.objects.all()
        serializer = NodeSerializer(nodes, many=True)
        return Response(serializer.data)

    def post(self, request, *args, **kwargs):
        node_serializer = NodeSerializer(data=request.data)
        if node_serializer.is_valid():
            node_serializer.save()
            return Response(node_serializer.data, status=status.HTTP_201_CREATED)
        else:
            print('error', node_serializer.errors)
            return Response(node_serializer.errors, status=status.HTTP_400_BAD_REQUEST)

class LinkView(viewsets.ModelViewSet):
    parser_classes = (MultiPartParser, FormParser)
    queryset = Link.objects.all()
    serializer_class = LinkSerializer

    def get(self, request, *args, **kwargs):
        links = Link.objects.all()
        serializer = LinkSerializer(links, many=True)
        return Response(serializer.data)

    def post(self, request, *args, **kwargs):
        link_serializer = LinkSerializer(data=request.data)
        if link_serializer.is_valid():
            link_serializer.save()
            return Response(link_serializer.data, status=status.HTTP_201_CREATED)
        else:
            print('error', link_serializer.errors)
            return Response(link_serializer.errors, status=status.HTTP_400_BAD_REQUEST)
