# $NetBSD: Makefile,v 1.28 2023/06/12 11:19:45 wen Exp $

DISTNAME=	Pod-POM-Web-1.27
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Pod/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Pod-POM-Web
COMMENT=	Perl 5 module providing a HTML Perldoc server
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Pod/POM/Web/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Alien-GvaScript>=1.21:../../www/p5-Alien-GvaScript
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-MIME-Types-[0-9]*:../../mail/p5-MIME-Types
DEPENDS+=	p5-Pod-POM>=0.25:../../textproc/p5-Pod-POM
DEPENDS+=	p5-URI-[0-9]*:../../www/p5-URI
DEPENDS+=	p5-libwww-[0-9]*:../../www/p5-libwww
DEPENDS+=	p5-CPAN-Common-Index-[0-9]*:../../devel/p5-CPAN-Common-Index

# recommends
DEPENDS+=	p5-AnnoCPAN-Perldoc-[0-9]*:../../devel/p5-AnnoCPAN-Perldoc
DEPENDS+=	p5-PPI-HTML-[0-9]*:../../textproc/p5-PPI-HTML
DEPENDS+=	p5-Search-Indexer>=1.0:../../textproc/p5-Search-Indexer

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
