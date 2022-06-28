# $NetBSD: Makefile,v 1.18 2022/06/28 11:37:10 wiz Exp $

DISTNAME=		CGI-Ajax-0.707
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		13
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		abs@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Ajax
COMMENT=		Call perl asynchronously from javascript

DEPENDS+=	p5-Class-Accessor>=0:../../devel/p5-Class-Accessor

PERL5_PACKLIST=		auto/CGI/Ajax/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
