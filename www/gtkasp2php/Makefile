# $NetBSD: Makefile,v 1.1.1.1 2001/11/22 11:32:29 agc Exp $

DISTNAME=	asp2php-0.75.24
PKGNAME=	gtk${DISTNAME}
CATEGORIES=	www
MASTER_SITES=	http://home.swbell.net/mikekohn/asp2php/

MAINTAINER=	shell@shellhung.org
HOMEPAGE=	http://asp2php.naken.cc/
COMMENT=	gtk+ version of utility to convert asp pages to php pages

WRKSRC=		${WRKDIR}/asp2php

ALL_TARGET=	all gtkasp2php

.include "../../x11/gtk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
