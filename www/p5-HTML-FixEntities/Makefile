# $NetBSD: Makefile,v 1.2 2002/02/01 16:18:58 abs Exp $

DISTNAME=		HTML-FixEntities-1.01
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/HTML-FixEntities/

MAINTAINER=		abs@netbsd.org
HOMEPAGE=		http://www.mono.org/abs/tools/HTML-FixEntities/
COMMENT=		perl5 module to convert latin1 to equivalent HTML

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/FixEntities/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
