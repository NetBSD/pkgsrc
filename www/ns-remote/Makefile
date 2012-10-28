# $NetBSD: Makefile,v 1.36 2012/10/28 06:30:23 asau Exp $

DISTNAME=	ns-remote-1.12
CATEGORIES=	www
MASTER_SITES=	http://ns-remote.googlecode.com/files/
EXTRACT_SUFX=	.tbz

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	http://code.google.com/p/ns-remote/
COMMENT=	Remote-control of Netscape and Mozilla-based browsers

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
