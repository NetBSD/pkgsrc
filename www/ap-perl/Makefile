# $NetBSD: Makefile,v 1.16 2001/11/23 10:53:12 martti Exp $
#

DISTNAME=		mod_perl-1.25
PKGNAME=		ap-perl-1.25nb1
CATEGORIES=		www perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Apache/} \
			http://perl.apache.org/dist/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://perl.apache.org/
COMMENT=		Module that embeds a Perl interpreter into Apache

DEPENDS+=		libperl>=${LIBPERL5_REQD}:../../lang/libperl
DEPENDS+=		apache{,6}-1.3.*:../../www/apache
DEPENDS+=		p5-BSD-Resource>=1.10:../../devel/p5-BSD-Resource

USE_PERL5=		# defined
LIBPERL5_REQD=		${PERL5_REQD}
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/mod_perl/.packlist

MAKE_PARAMS+=		USE_APXS=1
MAKE_PARAMS+=		WITH_APXS=${PREFIX}/sbin/apxs
MAKE_PARAMS+=		EVERYTHING=1

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/httpd/htdocs/manual/mod
	${INSTALL_DATA} ${WRKSRC}/htdocs/manual/mod/mod_perl.html \
		${PREFIX}/share/httpd/htdocs/manual/mod

.include "../../mk/bsd.pkg.mk"

.if exists(${PERL5_ARCHLIB}/DynaLoader_pic.o)
MAKE_ENV+=		DYNALOADER_OBJ_PIC="${PERL5_ARCHLIB}/DynaLoader_pic.o"
.endif
