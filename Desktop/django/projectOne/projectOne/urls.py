from django.contrib import admin
from django.urls import path, include
from django.contrib.auth import  views as auth_views
from users import  views as user_view

urlpatterns = [
    path('admin/', admin.site.urls),
    path('', include('blog.urls')),
    path('register/', user_view.register, name='register'),
    path('profile/', user_view.profile, name='profile'),
    path('login/', auth_views.LoginView.as_view( template_name='users/login.html' ), name='login'),
    path('logout/', auth_views.LogoutView.as_view(template_name='users/logout.html' ), name='logout'),

]

