from django.db import models

# Create your models here.

class ImgFile(models.Model):
        image = models.ImageField(upload_to='post_images')
        #name = models.CharField(max_length=200, default="{}".format(image.name))

        def __str__(self):
            return self.image.name #self.image

class Region(models.Model):
        x = models.IntegerField()
        y = models.IntegerField()
        width = models.IntegerField()
        height = models.IntegerField()
        facets = models.ForeignKey('Facet', on_delete=models.CASCADE)
        image = models.ForeignKey('ImgFile', on_delete=models.CASCADE)

        def __str__(self):
            return "Facet: {}".format(self.facets.name)

class Facet(models.Model):
        name = models.CharField(max_length=200)

        def __str__(self):
            return self.name
#models to make: File (an image with regions), Regions (an x,y,width,height,label transparency overlayed on the image), names (labels/facets applied to regions)
