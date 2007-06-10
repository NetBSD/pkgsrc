# $NetBSD: Makefile,v 1.1.1.1 2007/06/10 13:42:34 abs Exp $

DISTNAME=	Rose-DateTime-0.532
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Rose/}

MAINTAINER=	abs@absd.org
HOMEPAGE=	http://search.cpan.org/~jsiracusa/Rose-DB-Object/
COMMENT=	DateTime helper functions and objects for Rose

DEPENDS+= 	p5-Rose-Object>=0.82:../../devel/p5-Rose-Object
DEPENDS+=	p5-DateTime-[0-9]*:../../time/p5-DateTime

PERL5_PACKLIST=		auto/Rose/DateTime/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
