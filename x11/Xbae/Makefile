# $NetBSD: Makefile,v 1.32 2018/08/19 20:16:42 wiz Exp $

DISTNAME=	xbae-4.51.01
PKGNAME=	Xbae-4.51.01
PKGREVISION=	3
CATEGORIES=	x11
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xbae/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://xbae.sourceforge.net/
COMMENT=	Motif-compatible widgets: XbaeMatrix, XbaeCaption, XbaeInput

USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-motif-includes=${MOTIFBASE}/include
CONFIGURE_ARGS+=	--with-motif-libraries=${MOTIFBASE}/lib

INSTALLATION_DIRS=	share/aclocal

SUBST_CLASSES+=		dirs
SUBST_STAGE.dirs=	pre-configure
SUBST_FILES.dirs=	Makefile.in doc/Makefile.in doc/images/Makefile.in src/Makefile.in
SUBST_SED.dirs=		-e '/^mandir =/         s,=.*,= @mandir@,'
SUBST_SED.dirs+=	-e '/^SUBDIRS =/        s,examples,,'
SUBST_SED.dirs+=	-e '/^docdir =/         s,=.*,= $$(datadir)/doc/Xbae,'
SUBST_SED.dirs+=	-e '/^imagedir =/       s,=.*,= $$(datadir)/doc/Xbae/images,'
SUBST_SED.dirs+=	-e '/^install-data-am:/ s,install-htmlDATA,,'

post-install:
	${INSTALL_DATA} ${WRKSRC}/ac_find_xbae.m4 ${DESTDIR}${PREFIX}/share/aclocal

.include "../../mk/motif.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
