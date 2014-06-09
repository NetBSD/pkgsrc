# $NetBSD: options.mk,v 1.3 2014/06/09 12:23:00 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.py-django-tastypie
PKG_SUPPORTED_OPTIONS=	digest
PKG_SUGGESTED_OPTIONS+=	digest

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdigest)
PYTHON_VERSIONED_DEPENDENCIES+=	python-digest
.endif
