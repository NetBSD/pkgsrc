# $NetBSD: Makefile,v 1.4.2.1 2002/06/30 06:24:22 jlam Exp $

DISTNAME=	xml-i18n-tools-0.9
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=stable/sources/xml-i18n-tools/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://news.gnome.org/gnome-news/979851911/
COMMENT=	XML internationalisation tools

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GMAKE=		YES

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ABOUT-NLS AUTHORS COPYING ChangeLog NEWS README; do	\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
