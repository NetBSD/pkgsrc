# $NetBSD: Makefile,v 1.3 2001/08/27 19:15:55 tron Exp $

DISTNAME=	xml-i18n-tools-0.9
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/xml-i18n-tools/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://news.gnome.org/gnome-news/979851911/
COMMENT=	XML internationalisation tools

GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_PERL5=	YES

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/xml-i18n-tools
.for doc in ABOUT-NLS AUTHORS COPYING ChangeLog NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/xml-i18n-tools
.endfor

.include "../../mk/bsd.pkg.mk"
