# $NetBSD: Makefile,v 1.5 2002/12/09 19:17:19 abs Exp $

DISTNAME=		HTML-FixEntities-1.03
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		http://www.mono.org/abs/tools/HTML-FixEntities/

MAINTAINER=		abs@netbsd.org
HOMEPAGE=		http://www.mono.org/abs/tools/HTML-FixEntities/
COMMENT=		perl5 module to convert latin1 to equivalent HTML

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/HTML/FixEntities/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
