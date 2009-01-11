# $NetBSD: Makefile,v 1.3 2009/01/11 17:00:56 he Exp $
#

DISTNAME=	YAML-LibYAML-0.30
PKGNAME=	p5-${DISTNAME}
#PKGNAME=	p5-${DISTNAME:S/LibYAML/XS/}
CATEGORIES=	textproc perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN:=YAML/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/YAML-LibYAML/
COMMENT=	Perl XS binding to libyaml

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_REQD+=	5.8.3
PERL5_PACKLIST=	auto/YAML/LibYAML/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
