from rest_framework import serializers
from .models import *

class ImgFileSerializer(serializers.ModelSerializer):
    name = serializers.SerializerMethodField('image_name')

    def image_name(self, ImgFile):
        return ImgFile.image.name

    class Meta:
        model = ImgFile
        fields = ['id', 'name', 'image']

class FacetSerializer(serializers.ModelSerializer):
    class Meta:
        model = Facet
        fields = '__all__'

class RegionSerializer(serializers.ModelSerializer):
    class Meta:
        model = Region
        fields = '__all__'
