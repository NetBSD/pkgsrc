# $NetBSD: Makefile,v 1.32 2020/09/07 20:38:40 wiz Exp $

DISTNAME=		CGI-Minimal-1.30
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Minimal
COMMENT=		Perl5 module for simple CGI scripts
LICENSE=		mit

PERL5_PACKLIST=		auto/CGI/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
