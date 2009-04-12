# $NetBSD: Makefile,v 1.4 2009/04/12 01:30:41 sno Exp $
#

DISTNAME=	YAML-LibYAML-0.32
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
