# $NetBSD: Makefile,v 1.24 2026/08/30 14:36:56 wiz Exp $

DISTNAME=	yelp-xsl-42.4
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/yelp-xsl/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://www.gnome.org/
COMMENT=	XSL stylesheets for Yelp help browser
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND mit

TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

USE_TOOLS+=		bash pkg-config intltool msgfmt itstool
PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	yelp-xsl.pc.in

REPLACE_BASH+=	test/syntax/source/code/bash
REPLACE_BASH+=	xslt/common/domains/gen_yelp_xml.sh

.include "../../devel/meson/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../mk/bsd.pkg.mk"
