# $NetBSD: Makefile,v 1.17 2017/06/05 14:25:06 ryoon Exp $

DISTNAME=	Time-Local-1.25
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	time perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Time/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Time-Local/
COMMENT=	Efficiently compute time from local and GMT time
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Time/Local/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
