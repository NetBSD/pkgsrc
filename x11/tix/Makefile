# $NetBSD: Makefile,v 1.14 2000/10/09 18:04:37 hubertf Exp $
# $FreeBSD Id: Makefile,v 1.15 1998/03/17 07:55:17 tg Exp

DISTNAME=	Tix4.1.0.006
PKGNAME=	tix-4.1.0.006
CATEGORIES=	x11 tk80
MASTER_SITES=	ftp://ftp.xpi.com/pub/

BROKEN=		This package has not yet been updated to work with tcl-8.3.2.

MAINTAINER=	rh@vip.at

DEPENDS+=	tk-8.0.5:../../x11/tk

USE_X11=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/Tix4.1.0/unix/tk8.0
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-sam \
		--with-tcl="${PREFIX}/include/tcl8.0" \
		--with-tk="${PREFIX}/include/tk8.0"

pre-configure:
	@(cd ${WRKSRC}/.. && \
	    CC="${CC}" ac_cv_path_CC="${CC}" CFLAGS="${CFLAGS}" \
	    INSTALL="${INSTALL}" INSTALL_PROGRAM="${INSTALL_PROGRAM}" \
	  ${CONFIGURE_ENV} ${CONFIGURE_SCRIPT} ${CONFIGURE_ARGS})

post-install:
	@(cd ${WRKSRC}/.. && \
	    ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} -f ${MAKEFILE} ${INSTALL_TARGET})
	@${MKDIR} ${PREFIX}/man/man1
	@${MV} ${PREFIX}/man/mann/tixwish.1 ${PREFIX}/man/man1
	@${LN} -sf ${PREFIX}/bin/tixwish4.1.8.0 ${PREFIX}/bin/tixwish
.for dir in generic unix
	@${MKDIR} ${PREFIX}/include/tix/${dir}
	${INSTALL_DATA} ${WRKSRC}/../../${dir}/*.h ${PREFIX}/include/tix/${dir}
.endfor
	${RM} ${PREFIX}/include/tix/generic/tix.h
	@# These two files are the same
	${LN} -sf ../../tix.h ${PREFIX}/include/tix/generic

.include "../../mk/bsd.pkg.mk"
