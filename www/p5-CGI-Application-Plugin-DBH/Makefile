# $NetBSD: Makefile,v 1.20 2022/06/28 11:37:10 wiz Exp $

DISTNAME=		CGI-Application-Plugin-DBH-4.04
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/CGI-Application-Plugin-DBH
COMMENT=		Easy DBI access from CGI::Application
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application
DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI

PERL5_PACKLIST=		auto/CGI/Application/Plugin/DBH/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
