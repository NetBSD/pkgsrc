# $NetBSD: Makefile,v 1.12 2004/04/12 02:09:15 minskim Exp $

DISTNAME=	xml-i18n-tools-0.9
PKGREVISION=	1
CATEGORIES=	textproc gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/xml-i18n-tools/0.9/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://news.gnome.org/gnome-news/979851911/
COMMENT=	XML internationalisation tools

CONFLICTS=	intltool<=0.25

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES
USE_GNU_TOOLS+=		make

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

post-install:
	${INSTALL_DATA_DIR} ${DOCDIR}
	for file in ABOUT-NLS AUTHORS COPYING ChangeLog NEWS README; do	\
		${INSTALL_DATA} ${WRKSRC}/$${file} ${DOCDIR};		\
	done

.include "../../lang/perl5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
