# $NetBSD: Makefile,v 1.11 2004/01/24 15:13:20 grant Exp $

DISTNAME=	xml-i18n-tools-0.9
PKGREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/xml-i18n-tools/0.9/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://news.gnome.org/gnome-news/979851911/
COMMENT=	XML internationalisation tools

CONFLICTS=	intltool<=0.25

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ABOUT-NLS AUTHORS COPYING ChangeLog NEWS README; do	\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
