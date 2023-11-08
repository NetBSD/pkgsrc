# $NetBSD: Makefile,v 1.16 2023/11/08 13:21:11 wiz Exp $

DISTNAME=	yelp-tools-42.1
PKGREVISION=	1
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}

MAINTAINER=	pkgsrc.gnome@gmail.com
HOMEPAGE=	http://yelp.io/tools/
COMMENT=	Set of command-line tools to build and check your documentation
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

DEPENDS+=	itstool-[0-9]*:../../textproc/itstool
DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_TOOLS+=	pkg-config

REPLACE_PYTHON+=	tools/*.in

.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
BUILDLINK_API_DEPENDS.yelp-xsl=	yelp-xsl>=3.38
.include "../../textproc/yelp-xsl/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
