# $NetBSD: Makefile,v 1.1.1.1 2000/05/25 01:27:28 groo Exp $
#

DISTNAME=		type1inst-0.6.1
CATEGORIES=		x11
MASTER_SITES=		http://sunsite.unc.edu/pub/Linux/X11/xutils/

MAINTAINER=		groo@netbsd.org

USE_PERL5=		yes
USE_X11BASE=		yes

post-patch:
	@for patchee in ${WRKSRC}/type1inst ${WRKSRC}/t1embed; do \
		${MV} -f $$patchee ${WRKSRC}/foo ; \
		${SED} -e 's@XXXPERLXXX@${LOCALBASE}/bin/perl@g' \
			<${WRKSRC}/foo > $$patchee ; \
	done
	@${RM} -f ${WRKSRC}/foo

do-build:

do-install:
	@${INSTALL_SCRIPT} ${WRKSRC}/type1inst ${X11BASE}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/t1embed ${X11BASE}/bin
	@${INSTALL_MAN} ${WRKSRC}/type1inst.man ${X11BASE}/man/man1/type1inst.1
	@${MKDIR} ${X11BASE}/share/doc/type1inst
	@${INSTALL_DATA} ${WRKSRC}/README ${X11BASE}/share/doc/type1inst

.include "../../mk/bsd.pkg.mk"
