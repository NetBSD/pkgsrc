# $NetBSD: Makefile,v 1.38 2020/06/04 17:56:27 leot Exp $

DISTNAME=		wmii+ixp-3.9.2
PKGNAME=		wmii-3.9.2
CATEGORIES=		wm
MASTER_SITES=		http://dl.suckless.org/wmii/
EXTRACT_SUFX=		.tbz

MAINTAINER=		rares.aioanei@gmail.com
HOMEPAGE=		https://github.com/0intro/wmii
COMMENT=		Modular and keyboard-friendly window manager
LICENSE=		mit

DEPENDS+=		dmenu>=3.7:../../x11/dmenu

USE_TOOLS+=		tbl pkg-config

BUILD_DEFS+=		PKG_SYSCONFBASE
MAKE_ENV+=		PKG_SYSCONFBASE=${PKG_SYSCONFBASE}
# parallel compilations of at least cmd/util.o
MAKE_JOBS_SAFE=		no

# see ${WRKSRC}/mk/wmii.mk
CONFVERSION=		${PKGNAME:S/wmii-//}

EGDIR=			${PREFIX}/share/examples/wmii
EGSUBDIR.top=		# empty
EGFILES.top+=		wmiirc welcome
EGSUBDIR.pygmi=		python/pygmi
EGFILES.pygmi+=		__init__.py event.py fs.py menu.py monitor.py
EGFILES.pygmi+=		util.py
EGSUBDIR.pyxp=		python/pyxp
EGFILES.pyxp+=		__init__.py asyncclient.py client.py dial.py
EGFILES.pyxp+=		fcall.py fields.py messages.py mux.py types.py
EGSUBDIR.python=	python
EGFILES.python+=	wmiirc wmiirc.py
EGSUBDIR.ruby=		ruby
EGFILES.ruby+=		wmiirc config.rb config.yaml
CONF_FILES_MODE=	0644

.for subdir in top pygmi pyxp python ruby
.  for file in ${EGFILES.${subdir}}
CONF_FILES+=		${EGDIR}/${EGSUBDIR.${subdir}}/${file} \
			${PKG_SYSCONFDIR}/wmii-${CONFVERSION}/${EGSUBDIR.${subdir}}${file}
.  endfor
.endfor

LDFLAGS.SunOS+=		-lsocket -lnsl -liconv

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	pre-configure
SUBST_FILES.vars=	util/compile
SUBST_VARS.vars=	EGREP SED SH AWK

post-build:
	mv ${WRKSRC}/man/wmii.1 ${WRKSRC}/man/wmii.tbl
	${TBL} ${WRKSRC}/man/wmii.tbl > ${WRKSRC}/man/wmii.1

.include "../../converters/libiconv/buildlink3.mk"
# bundles it's own libixp, which is needed until a new stable release is out.
#.include "../../devel/libixp/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXinerama/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
