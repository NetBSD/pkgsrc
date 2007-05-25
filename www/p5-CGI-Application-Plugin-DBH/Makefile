# $NetBSD: Makefile,v 1.1.1.1 2007/05/25 11:29:58 markd Exp $

DISTNAME=		CGI-Application-Plugin-DBH-4.00
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=CGI/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/CGI-Application-Plugin-DBH
COMMENT=		Easy DBI access from CGI::Application

DEPENDS+=		p5-CGI-Application-[0-9]*:../../www/p5-CGI-Application
DEPENDS+=		p5-DBI-[0-9]*:../../databases/p5-DBI

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PERL5_PACKLIST=		auto/CGI/Application/Plugin/DBH/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
