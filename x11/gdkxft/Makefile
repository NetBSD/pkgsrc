# $NetBSD: Makefile,v 1.6 2002/09/10 16:06:52 wiz Exp $
#

DISTNAME=		gdkxft-1.5
PKGREVISION=		1
CATEGORIES=		x11
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=gdkxft/}

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://gdkxft.sourceforge.net/
COMMENT=		transparently add anti-aliased font support to gtk+ applications

.include "../../mk/bsd.prefs.mk"

.if !exists(${X11BASE}/lib/libXft.a)
IGNORE=			"${PKGNAME} requires XFree86-4.0 or higher"
.endif

GNU_CONFIGURE=		YES
USE_PERL5=		YES
USE_LIBTOOL=		YES
USE_X11BASE=		YES

LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig
USE_BUILDLINK_ONLY=	YES

CONFIGURE_ARGS+=	--enable-static

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/gdkxft
.for doc in AUTHORS COPYING ChangeLog INSTALL NEWS README
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/gdkxft
.endfor

.include "../../converters/libiconv/buildlink.mk"
.include "../../devel/libglade/buildlink.mk"
.include "../../x11/controlcenter/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
