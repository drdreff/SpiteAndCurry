from rest_framework import serializers
from .models import *

class ImgFileSerializer(serializers.ModelSerializer):
    name = serializers.SerializerMethodField('image_name')
    # linkedImages =

    def image_name(self, ImgFile):
        return ImgFile.image.name

    class Meta:
        model = ImgFile
        fields = ['id', 'url', 'name', 'image', 'linkedImages']

class FacetSerializer(serializers.ModelSerializer):
    class Meta:
        model = Facet
        fields = ['id', 'url', 'name']

class RegionSerializer(serializers.ModelSerializer):
    class Meta:
        model = Region
        fields = ['id', 'url', 'x', 'y', 'width', 'height', 'facets', 'image']

class LinkSerializer(serializers.ModelSerializer):
    class Meta:
        model = Link
        fields = ['id', 'url', 'source', 'target']

class NodeSerializer(serializers.ModelSerializer):

    class Meta:
        model = Node
        fields = ['id', 'url', 'node', 'image']
