# $NetBSD: Makefile,v 1.43 2006/11/14 13:56:15 joerg Exp $
#

DISTNAME=		scrollkeeper-0.3.14
PKGREVISION=		10
CATEGORIES=		textproc
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=scrollkeeper/}	\
			${MASTER_SITE_GNOME:=sources/scrollkeeper/0.3/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://scrollkeeper.sourceforge.net/
COMMENT=		Open Document Cataloging Project

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		docbook-xml>=4.4nb4:../../textproc/docbook-xml

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes

CONFIGURE_ARGS+= 	--localstatedir=${SCROLLKEEPER_DATADIR:Q}
CONFIGURE_ARGS+=	--sharedstatedir=${SCROLLKEEPER_DATADIR:Q}
CONFIGURE_ARGS+= 	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+= 	--with-partial-db-dir=db
CONFIGURE_ARGS+= 	--with-xml-catalog=${BUILDLINK_PREFIX.xmlcatmgr}/share/xml/catalog

.include "../../mk/bsd.prefs.mk"

.if ${LOCALBASE} == ${X11PREFIX}
CONFIGURE_ARGS+=	--with-omfdirs=${PREFIX}/share/omf
.else
CONFIGURE_ARGS+=	--with-omfdirs=${LOCALBASE}/share/omf:${X11PREFIX}/share/omf
.endif

SCROLLKEEPER_DATADIR=	${PREFIX}/libdata/scrollkeeper
SCROLLKEEPER_REBUILDDB=	${PREFIX}/bin/scrollkeeper-rebuilddb
FILES_SUBST+=		SCROLLKEEPER_DATADIR=${SCROLLKEEPER_DATADIR:Q}
FILES_SUBST+=		SCROLLKEEPER_REBUILDDB=${SCROLLKEEPER_REBUILDDB:Q}

EGDIR=		${PREFIX}/share/examples/scrollkeeper
CONF_FILES=	${EGDIR}/scrollkeeper.conf ${PKG_SYSCONFDIR}/scrollkeeper.conf

XML_ENTRIES=	public "-//Scrollkeeper//DTD Contents List V1.0//EN" \
		${PREFIX}/share/xml/scrollkeeper/dtds/scrollkeeper-cl.dtd
XML_ENTRIES+=	public "-//OMF//DTD Scrollkeeper OMF Variant V1.0//EN" \
		${PREFIX}/share/xml/scrollkeeper/dtds/scrollkeeper-omf.dtd
XML_ENTRIES+=	public "-//Open Source Metadata Framework (OMF) //DTD OMF.dtd V1.1//EN" \
		${PREFIX}/share/xml/scrollkeeper/dtds/scrollkeeper-omf.dtd

SUBST_CLASSES+=		sk-config sc-gtfd
SUBST_STAGE.sk-config=	post-patch
SUBST_FILES.sk-config=  scripts/scrollkeeper-get-index-from-docpath.in \
			scripts/scrollkeeper-get-toc-from-docpath.in \
			scripts/scrollkeeper-get-toc-from-id.in \
			scripts/scrollkeeper-rebuilddb.in \
			cl/src/get-cl.c \
			cl/src/update.c \
			cl/src/scrollkeeper-install.c \
			cl/src/scrollkeeper-uninstall.c
SUBST_SED.sk-config=    -e s,scrollkeeper-config\ ,${PREFIX}/bin/scrollkeeper-config\ ,
SUBST_STAGE.sc-gtfd=	post-patch
SUBST_FILES.sc-gtfd=	libs/install.c
SUBST_SED.sc-gtfd=	-e s,scrollkeeper-get-toc-from-docpath\ ,${PREFIX}/bin/scrollkeeper-get-toc-from-docpath\ ,

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/xmlcatmgr/catalogs.mk"

.include "../../mk/bsd.pkg.mk"
