from django.urls import include, path
from . import views
from rest_framework import routers

router = routers.DefaultRouter()
router.register(r'imgfiles', views.ImgFileView)
router.register(r'regions', views.RegionView)
router.register(r'facets', views.FacetView)
router.register(r'nodes', views.NodeView)
router.register(r'links', views.LinkView)

urlpatterns = [
    path('', include(router.urls)),
    #path('posts/', views.PostView.as_view(), name= 'posts_list'),
]
