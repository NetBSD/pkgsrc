# $OpenBSD: Makefile,v 1.5 2000/10/23 16:08:12 espie Exp $
# $NetBSD: Makefile,v 1.1.1.1 2000/10/29 16:17:13 mjl Exp $

PKGVER=		2.1.30
DISTNAME=	openmotif${PKGVER}
PKGNAME=	openmotif-${PKGVER}
CATEGORIES=	x11
MASTER_SITES=	ftp://openmotif.opengroup.org/pub/openmotif/R${PKGVER}/tars/ \
		ftp://ftp.opengroup.org/pub/openmotif/R${PKGVER}/tars/ \
		ftp://ftp.kddlabs.co.jp/X11/openmotif/R${PKGVER}/tars/

PATCH_SITES=	ftp://openmotif.opengroup.org/pub/openmotif/R${PKGVER}/fixes/ \
		ftp://ftp.opengroup.org/pub/openmotif/R${PKGVER}/fixes/ \
		ftp://ftp.kddlabs.co.jp/X11/openmotif/R${PKGVER}/fixes/
PATCHFILES=	patch1 patch2 patch3 patch4 patch5
PATCH_DIST_STRIP=-p1

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.opengroup.org/openmotif/

WRKSRC=		${WRKDIR}/motif
USE_X11BASE=	yes
ALL_TARGET=	World

post-patch:
# fix sections
	cd ${WRKSRC}/doc/man; for n in man1/*.1 man3/*.3 man4/*.4 man5/*.5 ; \
		do ${SED} 's/user cmd/1/g; s/library call/3/g; s/special file/5/g; s/file formats/5/g;' $$n >$$n.new && ${MV} -f $$n.new $$n; done
	${MV} -f ${WRKSRC}/doc/man/man4/mwmrc.4 ${WRKSRC}/doc/man/man5/mwmrc.5
	@cd ${WRKSRC}/config/cf && \
	    ${SED} -e "s|%%PREFIX%%|${PREFIX}|g" < site.def > site.def.new && \
	    ${MV} -f site.def.new site.def && \
	    ${SED} -e "s|%%PREFIX%%|${PREFIX}|g" < Motif.tmpl > Motif.tmpl.new && \
	    ${MV} -f Motif.tmpl.new Motif.tmpl
	${CP} -f `ls ${X11BASE}/lib/X11/config/* | ${GREP} -v '\(Motif\|cde\|\/site.def\)'` ${WRKDIR}/motif/config/cf
	${MKDIR} ${WRKSRC}/imports/x11
	@cd ${WRKSRC}/imports/x11 && for i in bin include lib ; do \
	    if [ -f $$i ] ; then ${RM} $$i; fi; \
	    ${LN} -s ${X11BASE}/$$i $$i; \
	done

# tblize the manpages.
post-build:
	for i in man1 man3 man5 ; do cd ${WRKSRC}/doc/man/$$i; \
		for m in *.[135]; do tbl $$m > $$m.new && ${MV} -f $$m.new $$m; done; \
	done

# Install the manpages.
post-install:
	for i in man1 man3 man5 ; do cd ${WRKSRC}/doc/man/$$i; \
	    ${MKDIR} ${PREFIX}/man/$$i; \
	    for m in *.[135]; do ${INSTALL_MAN} $$m ${PREFIX}/man/$$i; done; \
	done

.include <../../mk/bsd.pkg.mk>
