# $NetBSD: Makefile,v 1.2 1999/05/02 18:04:50 rh Exp $

DISTNAME=		WindowMaker-extra-0.1
PKGNAME=		wmextra-0.1
CATEGORIES=		x11
MASTER_SITES=		ftp://ftp.windowmaker.org/pub/beta/srcs/ \
			ftp://shadowmere.student.utwente.nl/pub/WindowMaker/

MAINTAINER=		jlam@netbsd.org
HOMEPAGE=		http://www.windowmaker.org/

DEPENDS+=		windowmaker-0.53.0:../../x11/windowmaker

USE_X11BASE=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
			INSTALL_DATA="${INSTALL_DATA}" \
			INSTALL_SCRIPT="${INSTALL_SCRIPT}"

.include "../../mk/bsd.pkg.mk"
