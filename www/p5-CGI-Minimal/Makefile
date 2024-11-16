# $NetBSD: Makefile,v 1.36 2024/11/16 12:07:29 wiz Exp $

DISTNAME=		CGI-Minimal-1.30
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		4
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Minimal
COMMENT=		Perl5 module for simple CGI scripts
LICENSE=		mit

PERL5_PACKLIST=		auto/CGI/Minimal/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
