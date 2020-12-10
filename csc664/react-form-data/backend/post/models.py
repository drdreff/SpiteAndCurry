from django.db import models

# Create your models here.

class ImgFile(models.Model):
        image = models.ImageField(upload_to='post_images')
        linkedImages = models.ManyToManyField('self', symmetrical=False, blank=True)

        def __str__(self):
            return self.image.name #self.image

class Region(models.Model):
        x = models.TextField(max_length=4)
        y = models.TextField(max_length=4)
        width = models.TextField(max_length=4)
        height = models.TextField(max_length=4)
        facets = models.ForeignKey('Facet', on_delete=models.CASCADE)
        image = models.ForeignKey('ImgFile', on_delete=models.CASCADE)

        def __str__(self):
            return "Facet: {}".format(self.facet.name)

class Facet(models.Model):
        name = models.CharField(max_length=200)

        def __str__(self):
            return self.name

class Node(models.Model):
        node = models.ForeignKey('ImgFile', on_delete=models.CASCADE)
        image = models.ImageField(upload_to=None)

        def __str__(self):
            return self.id

class Link(models.Model):
        source = models.ForeignKey('ImgFile', related_name='source_image', on_delete=models.CASCADE)
        target = models.ForeignKey('ImgFile', related_name='destination_image', on_delete=models.CASCADE)

        def __str__(self):
            return self.id
#models to make: File (an image with regions), Regions (an x,y,width,height,label transparency overlayed on the image), names (labels/facets applied to regions)
'''

def get_graph(parent, facet):
    temp1 = ImgFile.objects.get(pk=parent)
    node = Node.objects.create(pk=parent, node=temp1)
    temp2 = ImgFile.objects.filter(region__facets=facet).filter(id__in=temp1.linkedImages.all()).distinct()
    for image in temp2:
        link = Link.objects.create(source=temp1, destination=image)
        try:
            temp3 = ImgFile.objects.get(pk=image.pk)
            node = Node.objects.create(pk=image.pk, node=temp3)
        except IntegrityError:
            break
        get_graph(image.id, facet)


array = []
def get_links(parent):
    for image in parent.linkedImages.all():
        array.append([parent.id, image.id])
        print('{}-{}'.format(parent.id, image.id))
        if [image.id, parent.id] not in array:
            get_links(image)

'''
