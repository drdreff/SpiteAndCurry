# Generated by Django 3.1.2 on 2020-11-01 02:53

from django.db import migrations, models


class Migration(migrations.Migration):

    dependencies = [
        ('post', '0004_imgfile_name'),
    ]

    operations = [
        migrations.AlterField(
            model_name='imgfile',
            name='name',
            field=models.CharField(default=None, max_length=200, null=True),
        ),
    ]