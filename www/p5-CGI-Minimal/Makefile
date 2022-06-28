# $NetBSD: Makefile,v 1.34 2022/06/28 11:37:11 wiz Exp $

DISTNAME=		CGI-Minimal-1.30
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Minimal
COMMENT=		Perl5 module for simple CGI scripts
LICENSE=		mit

PERL5_PACKLIST=		auto/CGI/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
