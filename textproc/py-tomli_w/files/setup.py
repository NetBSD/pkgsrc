#!/usr/bin/env python

from setuptools import setup

packages = \
['tomli_w']

package_data = \
{'': ['*']}

setup(name='tomli_w',
      version='1.0.0',
      description="A lil' TOML writer",
      author=None,
      author_email='Taneli Hukkinen <hukkin@users.noreply.github.com>',
      url=None,
      packages=packages,
      package_data=package_data,
      python_requires='>=3.7',
     )
