# $NetBSD: Makefile,v 1.22 2009/02/27 17:52:02 wiz Exp $
#
# PKGNAME derives from the supported API (still from
# release 3.14). See also PLIST.
#

DISTNAME=	gtkhtml-3.24.5
PKGNAME=	${DISTNAME:S/gtkhtml/gtkhtml314/}
CATEGORIES=	www gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gtkhtml/3.24/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Lightweight HTML rendering/printing/editing engine

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=		yes
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	components/editor/gtkhtml-editor.pc.in
PKGCONFIG_OVERRIDE+=	gtkhtml/libgtkhtml.pc.in

# The gettext version in pkgsrc cannot handle the .po files, so
# we strip out usage of the newer features (context and fuzzy matches)
post-patch:
	for f in ${WRKSRC}/po/*.po ; do \
	    mv $$f $$f.original ; \
	    ${AWK} -f ${FILESDIR}/msgfmtstrip $$f.original > $$f ; \
	done

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../net/ORBit2/buildlink3.mk"
.include "../../net/libsoup24/buildlink3.mk"
.include "../../textproc/enchant/buildlink3.mk"
.include "../../textproc/iso-codes/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
