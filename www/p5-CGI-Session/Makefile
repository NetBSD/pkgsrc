# $NetBSD: Makefile,v 1.34 2023/07/06 09:42:24 wiz Exp $

DISTNAME=		CGI-Session-4.48
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		12
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Session
COMMENT=		Perl5 module providing session management across HTTP requests
LICENSE=		${PERL5_LICENSE}

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/CGI/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
