# $NetBSD: Makefile,v 1.12 2004/12/03 15:15:12 wiz Exp $
#

DISTNAME=	asp2php-0.76.17
PKGNAME=	gtk${DISTNAME}
PKGREVISION=	1
CATEGORIES=	www
MASTER_SITES=	http://65.108.58.129/asp2php/

MAINTAINER=	shell@NetBSD.org
HOMEPAGE=	http://asp2php.naken.cc/
COMMENT=	Gtk+ version of utility to convert asp pages to php pages

USE_BUILDLINK3=	YES

BUILD_TARGET=	all gui

.include "../../x11/gtk/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
