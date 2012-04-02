# $NetBSD: hacks.mk,v 1.2 2012/04/02 10:23:48 markd Exp $

.if ${OPSYS} == "NetBSD"
post-configure:
	cp ${FILESDIR}/kshareddatacache.cpp ${WRKSRC}/kdecore/util/kshareddatacache.cpp
.endif

# fix up buildlinks failure to build link tree correctly
post-wrapper:
	ln -s ${BUILDLINK_PREFIX.qt4-libs}/qt4/mkspecs/default ${BUILDLINK_DIR}/qt4/mkspecs/default
