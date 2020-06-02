# $NetBSD: Makefile,v 1.33 2020/06/02 08:24:59 adam Exp $
#

CLISP_MODULE=	gtk2

PKGNAME=	clisp-${CLISP_MODULE}-${CLISP_VERSION}
PKGREVISION=	31
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=clisp/}

MAINTAINER=	asau@inbox.ru
HOMEPAGE=	http://clisp.cons.org/
COMMENT=	CLISP GIMP Toolkit v2 (GTK2) module

MAKE_JOBS_SAFE=	no

.include "../../lang/clisp/module.mk"

USE_TOOLS+=	pkg-config

.include "../../devel/libglade/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
