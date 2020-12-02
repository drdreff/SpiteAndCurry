from django.shortcuts import render
from django.shortcuts import get_object_or_404
from .serializers import *
from .models import *
from rest_framework import viewsets
from rest_framework.views import APIView
from rest_framework.parsers import MultiPartParser, FormParser
from rest_framework.response import Response
from rest_framework import status
# Create your views here.

class ImgFileView(viewsets.ModelViewSet):
    parser_classes = (MultiPartParser, FormParser)
    queryset = ImgFile.objects.all()
    serializer_class = ImgFileSerializer

    def get(self, request, *args, **kwargs):
        imgFiles = ImgFile.objects.all()
        serializer = ImgFileSerializer(imgFiles, many=True)
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
