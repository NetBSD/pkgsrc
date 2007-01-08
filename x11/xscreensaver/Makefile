# $NetBSD: Makefile,v 1.82 2007/01/08 21:45:10 drochner Exp $

PKGREVISION=	1

COMMENT=	Screen saver and locker for the X window system

CONFLICTS+=	xscreensaver-gnome<4.14

.include "Makefile.common"

CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--with-xml=${BUILDLINK_PREFIX.libxml2}
CONFIGURE_ARGS+=	--with-configdir=${PREFIX}/libexec/xscreensaver/config

EGDIR=			${PREFIX}/share/examples/xscreensaver
MESSAGE_SUBST+=		EGDIR=${EGDIR:Q}

.include "options.mk"
.include "../../textproc/libxml2/buildlink3.mk"

# Remove useless locale files that have no translations in them.
post-extract:
	cd ${WRKSRC}/po && ${RM} -f ca.po pt_BR.po

post-install: installpamex
installpamex:
	${INSTALL_DATA_DIR} ${EGDIR}/pam.d
	${INSTALL_DATA} ${FILESDIR}/pam-xscreensaver-NetBSD \
                ${EGDIR}/pam.d/xscreensaver-NetBSD

.include "../../mk/bsd.pkg.mk"
