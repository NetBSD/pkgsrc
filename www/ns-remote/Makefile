# $NetBSD: Makefile,v 1.37 2017/01/04 22:14:56 abs Exp $

DISTNAME=	ns-remote-1.12
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GITHUB:=abs0/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	https://github.com/abs0/ns-remote
COMMENT=	Remote-control of Netscape and Mozilla-based browsers

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
