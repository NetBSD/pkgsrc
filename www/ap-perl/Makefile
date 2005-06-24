# $NetBSD: Makefile,v 1.36 2005/06/24 05:56:26 jlam Exp $
#

DISTNAME=		mod_perl-1.29
PKGNAME=		ap-perl-1.29
PKGREVISION=		2
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/} \
			http://perl.apache.org/dist/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

CONFLICTS=		ap2-perl-[0-9]*

DEPENDS+=		${BUILDLINK_DEPENDS.apache}:../../www/apache
DEPENDS+=		p5-BSD-Resource>=1.10:../../devel/p5-BSD-Resource

APACHE_MODULE=		YES
PERL5_REQD+=		5.8.0
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${APXS}
MAKE_PARAMS+=		EVERYTHING=1

.include "../../lang/perl5/module.mk"
.include "../../www/apache/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod

.include "../../mk/bsd.pkg.mk"
