#!/usr/bin/env python

from setuptools import setup

packages = \
['tomli']

package_data = \
{'': ['*']}

setup(name='tomli',
      version='2.0.0',
      description="A lil' TOML parser",
      author=None,
      author_email='Taneli Hukkinen <hukkin@users.noreply.github.com>',
      url=None,
      packages=packages,
      package_data=package_data,
      python_requires='>=3.7',
     )
