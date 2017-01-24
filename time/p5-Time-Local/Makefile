# $NetBSD: Makefile,v 1.16 2017/01/24 04:45:08 wen Exp $

DISTNAME=	Time-Local-1.25
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Local/
COMMENT=	Efficiently compute time from local and GMT time
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Time/Local/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
