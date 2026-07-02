# $NetBSD: Makefile,v 1.37 2026/07/02 08:59:08 wiz Exp $

DISTNAME=		CGI-Session-4.49
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MA/MARKSTOS/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Session
COMMENT=		Perl5 module providing session management across HTTP requests
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-CGI-[0-9]*:../../www/p5-CGI
DEPENDS+=		p5-Crypt-SysRandom-[0-9]*:../../security/p5-Crypt-SysRandom

PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/CGI/Session/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
