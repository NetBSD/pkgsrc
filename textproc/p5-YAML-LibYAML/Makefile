# $NetBSD: Makefile,v 1.8 2011/11/16 08:38:26 sno Exp $
#

DISTNAME=	YAML-LibYAML-0.37
PKGNAME=	p5-${DISTNAME}
#PKGNAME=	p5-${DISTNAME:S/LibYAML/XS/}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/YAML-LibYAML/
COMMENT=	Perl XS binding to libyaml
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/YAML/LibYAML/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
