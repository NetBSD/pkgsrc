# $NetBSD: hacks.mk,v 1.1 2012/03/19 11:28:48 markd Exp $

.if ${OPSYS} == "NetBSD"
post-configure:
	cp ${FILESDIR}/kshareddatacache.cpp ${WRKSRC}/kdecore/util/kshareddatacache.cpp
.endif

# fix up buildlinks failure to build link tree correctly
post-wrapper:
	ln -s netbsd-g++ ${BUILDLINK_DIR}/qt4/mkspecs/default
