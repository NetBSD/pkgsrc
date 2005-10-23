# $NetBSD: Makefile,v 1.1.1.1 2005/10/23 20:39:03 minskim Exp $
#

DISTNAME=	wmii-20051017
CATEGORIES=	wm x11
MASTER_SITES=	http://wmii.de/snaps/

MAINTAINER=	lems@gmx.net
HOMEPAGE=	http://wmii.de/
COMMENT=	Modular and keyboard-friendly window manager

DEPENDS+=		9rc-[0-9]*:../../shells/9rc

USE_PKGINSTALL=		yes
NO_CONFIGURE=		yes

CFLAGS.SunOS+=		-D__EXTENSIONS__

SUBST_CLASSES+=		vars
SUBST_STAGE.vars=	post-patch
SUBST_FILES.vars=	base/wmii util/wmirefcard action/* base/wmii.1
SUBST_SED.vars=		-e 's|SHAREPREFIX|${PREFIX}/share|g'
SUBST_SED.vars+=	-e 's|CONFPREFIX|${PREFIX}/share/examples|g'
SUBST_SED.vars+=	-e 's|9PREFIX|${PREFIX}|g'

PKG_SYSCONFSUBDIR=	wmii
EGDIR=			${PREFIX}/share/examples/wmii
EGFILES=		actions attach border clientupdate	\
			close cnext cprev detach fnext fprev	\
			fresize ftoggle	icons kbare kmove 	\
			knorm kresize lfloat lgrid lmax lock	\
			ltiled lvsplit max p pager pageupdate	\
			plumbgoogle plumburl pnew pnext pprev 	\
			premove presize programs ptoggle quit	\
			scr status tab term wmirc wmire www	\
			zoom
.for f in ${EGFILES}
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor
.undef f

.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
