# $NetBSD: Makefile,v 1.3 2001/02/12 04:14:29 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		imap
CATEGORIES+=		mail

# We want something like:
# BUILD_DEPENDS+=	imap-uw>=2000.0.3nb1:../../mail/imap-uw
#
BUILD_DEPENDS+=		${CCLIENT_PIC_LIB}:../../mail/imap-uw

CCLIENT_PIC_LIB=	${LOCALBASE}/lib/libc-client_pic.a

CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${LOCALBASE}
CONFIGURE_ARGS+=	--with-${MODNAME}-ssl=shared,${SSLBASE}

USE_SSL=		# defined

MAKE_ENV+=		LTLIBRARY_OBJECTS_X="${CCLIENT_PIC_LOBJS}"

pre-build:
	cd ${WRKSRC}/ext/imap;						\
	${AR} x ${CCLIENT_PIC_LIB};					\
	for file in ${CCLIENT_PIC_OBJS}; do				\
		base=`basename $${file} .o`;				\
		${LN} -sf $${file} $${base}.lo;				\
		${LN} -sf $${file} $${base}.slo;			\
	done

.include "../../mk/bsd.pkg.mk"

.if exists(${CCLIENT_PIC_LIB}) && !defined(CCLIENT_PIC_OBJS)
CCLIENT_PIC_OBJS!=	${AR} t ${CCLIENT_PIC_LIB}
CCLIENT_PIC_LOBJS=	${CCLIENT_PIC_OBJS:S/.o/.lo/g}
.endif
