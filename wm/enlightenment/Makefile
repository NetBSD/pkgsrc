# $NetBSD: Makefile,v 1.8 2001/10/24 22:11:09 jlam Exp $

DISTNAME=		enlightenment-0.16.4
CATEGORIES=		x11 gnome wm
MASTER_SITES=		ftp://ftp.enlightenment.org/pub/e/enlightenment/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.enlightenment.org/
COMMENT=		Window manager for X

USE_BUILDLINK_ONLY=	yes
USE_PERL5=		yes
USE_X11BASE=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-fsstd
MAKE_ENV+=		USER=${SHAREOWN}:${SHAREGRP}

# Remove -I$(includedir) from the INCLUDES passed to the compiler as this
# defeats buildlink.
#
post-patch:
	cd ${WRKSRC};							\
	files=`${FIND} . -name "Makefile.in" -print`;			\
	for file in $${files}; do					\
		${MV} -f $${file} $${file}.fixme;			\
		${SED} -e "/^INCLUDES.*=.*/s|[  ]*-I\$$(includedir)||"	\
			$${file}.fixme > $${file};			\
		${RM} $${file}.fixme;					\
	done

post-install:
	for FILE in `${GREP} "\.directory$$" ${PKGDIR}/PLIST`; do \
	  ${TOUCH} ${PREFIX}/$${FILE}; \
	done
	${FIND} ${PREFIX}/share/enlightenment/themes -type d | \
	${XARGS} ${CHMOD} ${BINMODE}
	${FIND} ${PREFIX}/share/enlightenment/themes -type f | \
	${XARGS} ${CHMOD} ${NONBINMODE}

.include "../../audio/esound/buildlink.mk"
.include "../../graphics/imlib/buildlink.mk"
.include "../../graphics/fnlib/buildlink.mk"
.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../www/libghttp/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
