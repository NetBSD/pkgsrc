# $NetBSD: Makefile,v 1.16 2001/09/22 10:45:09 skrll Exp $
#

DISTNAME=	kdelibs-2.1.2
CATEGORIES=	x11 kde
.include "../../x11/kde2/Makefile.part1"
MASTER_SITES=   ftp://ftp.kde.org/pub/kde/stable/2.1.2/distribution/tar/generic/src/ \
                ftp://ftp.us.kde.org/pub/kde/stable/2.1.2/distribution/tar/generic/src/ \
                ftp://ftp.de.kde.org/pub/kde/stable/2.1.2/distribution/tar/generic/src/
COMMENT=	Support libraries for the KDE integrated X11 desktop

DEPENDS+=		jade>=1.2.1:../../textproc/jade
BUILDLINK_DEPENDS.audiofile=	libaudiofile>=0.1.9
USE_BUILDLINK_ONLY=	yes

.include "../../x11/kde2/Makefile.part2"

LTCONFIG_OVERRIDE+=	${WRKSRC}/ksgmltools/ltconfig

.include "../../mk/bsd.prefs.mk"

.if (defined(KJS_USE_PCRE) && ${KJS_USE_PCRE} == yes)
.include "../../devel/pcre/buildlink.mk"
.endif

CONFIGURE_ARGS+=	--with-ssl-dir="${BUILDLINK_DIR}"
CONFIGURE_ENV+=		USER_LDFLAGS="${USER_LDFLAGS}"
LIBS+=			-Wl,--export-dynamic
USER_LDFLAGS=		-L${BUILDLINK_DIR}/lib
USER_LDFLAGS+=		-Wl,-R${LOCALBASE}/lib
USER_LDFLAGS+=		-Wl,-R${X11BASE}/lib

MKDIRS=	share/kde/icons/locolor/32x32/actions/kde \
	share/kde/icons/locolor/22x22/mimetypes \
	share/kde/icons/locolor/22x22/filesystems \
	share/kde/icons/locolor/22x22/actions/kde \
	share/kde/icons/hicolor/22x22/mimetypes \
	share/kde/icons/hicolor/22x22/filesystems

KDE_RPATH_MAKEFILES=	dcop/Makefile.in

# Add a missing $(KDE_RPATH) to the LDFLAGS setting in several Makefiles.
post-patch:
	@cd ${WRKSRC};							\
	for file in ${KDE_RPATH_MAKEFILES}; do				\
		${SED}	-e "s,\(^LDFLAGS.*\),\1 \$$(KDE_RPATH),"	\
			$${file} > $${file}.add-kde-rpath;		\
		${MV} -f $${file}.add-kde-rpath $${file};		\
	done

post-install:
	for d in ${MKDIRS}; do \
		${INSTALL_DATA_DIR} ${PREFIX}/$$d; \
	done

.include "../../archivers/bzip2/buildlink.mk"
.include "../../audio/libaudiofile/buildlink.mk"
.include "../../devel/libtool/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../security/openssl/buildlink.mk"

.include "../../mk/bsd.pkg.mk"
